class Codec:
    def __init__(self):
        self.map = dict()
        self.count = 0
    def encode(self, longUrl: str) -> str:
        """Encodes a URL to a shortened URL.
        """
        self.map[self.count] = longUrl
        self.count += 1
        return f"http://tinyurl.com/{self.count}"
        

    def decode(self, shortUrl: str) -> str:
        """Decodes a shortened URL to its original URL.
        """
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))