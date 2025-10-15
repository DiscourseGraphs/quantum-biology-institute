# _ext/obsidian_links.py
import re
from pathlib import Path

# Matches ![[path]] (embed) or [[path]] (link)
EMBED = re.compile(r'!\[\[([^\]]+)\]\]')
LINK  = re.compile(r'(?<!\!)\[\[([^\]]+)\]\]')

IMAGE_EXTS = {".png", ".jpg", ".jpeg", ".gif", ".svg", ".webp"}
DOWNLOAD_ROLE = "{download}`{path}`"

def _rewrite(text):
    # 1) Handle embeds: ![[...]]
    def repl_embed(m):
        raw = m.group(1).strip()
        p = Path(raw)
        # If it looks like an image, convert to Markdown image embed
        if p.suffix.lower() in IMAGE_EXTS:
            # Use the filename (without ext) as alt text
            alt = p.stem.replace("_", " ")
            return f"![{alt}]({raw})"
        # Otherwise, make it a MyST download role
        return DOWNLOAD_ROLE.format(path=raw)

    # 2) Handle simple wiki links: [[...]] → normal link text
    def repl_link(m):
        raw = m.group(1).strip()
        text = Path(raw).stem.replace("_", " ")
        return f"[{text}]({raw})"

    text = EMBED.sub(repl_embed, text)
    text = LINK.sub(repl_link, text)
    return text

def setup(app):
    def on_source_read(app, docname, source):
        # source is a list of one string
        source[0] = _rewrite(source[0])

    app.connect("source-read", on_source_read)
    return {"version": "0.1", "parallel_read_safe": True}
