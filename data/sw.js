console.log('porcodio')
const staticVDSAutomation = "vds-automation-app-v1";
const assets = [
  "/",
  "/index.html",
  "/src/bootstrap.min.css",
  "/src/bootstrap.bundle.min.js",
  "/src/jquery-3.6.0.min.js",
];

self.addEventListener("install", installEvent => {
  installEvent.waitUntil(
    caches.open(staticVDSAutomation).then(cache => {
      cache.addAll(assets);
    })
  );
});

self.addEventListener("fetch", fetchEvent => {
  fetchEvent.respondWith(
    caches.match(fetchEvent.request).then(res => {
      return res || fetch(fetchEvent.request);
    })
  );
});