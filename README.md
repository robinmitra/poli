# PoliDB
An simple, experimental embeddable key-value store.

## Todo

### Operations
- [x] Put
- [x] Get
- [x] Delete
- [x] Iterate
- [ ] Batch operations

### Features
- [ ] Persist to filesystem
- [ ] Multiple stores 
- [ ] Arbitrary data storage (currently, only string values are allowed)
- [ ] Background daemon
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
