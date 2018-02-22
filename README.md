# PoliDB
An simple, experimental embeddable key-value store.

## Todo

### Operations
- [x] Put
- [x] Get
- [ ] Delete
- [ ] Iterate
- [ ] Batch operations

### Features
- [ ] Persist to filesystem
- [ ] Background daemon
- [ ] Multiple stores 
- [ ] Arbitrary data storage (currently, only string values are allowed)
- [ ] Atomic batch transactions
- [ ] Backup and restore (and potentially snapshots?)
- [ ] Configuration

### Misc
- [ ] Unit tests
- [ ] Benchmarks and performance profiling
- [ ] Extract Trie to own package
- [ ] Better README
- [ ] Performance! - support for scaling across multiple cores, machine clusters, etc.
- [ ] Compression

### Ideas
- [ ] RESTful API, probably as a separate application 
- [ ] TTL
- [ ] Multi-process access - start with read-only access
- [ ] Ability to run on CPU vs GPU?
- [ ] Replication
- [ ] Rate limiter
