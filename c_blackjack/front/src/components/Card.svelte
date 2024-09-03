<script>
  let suit = "♥";
  let value = 9;
</script>

<div class="card">
  <div class="top">{suit}</div>
  <div class="mid">{value}</div>
  <div class="bottom">{suit}</div>
</div>

<style>
  .card {
    color: red;
    width: 16rem;
    padding: 1rem 2rem;
    border: 1px solid black;
    border-radius: 2rem;
    box-shadow: 1rem 1rem rgba(0, 0, 0, 0.2);
    font-size: 8rem;
  }
  .mid {
    text-align: center;
  }
  .bottom {
    text-align: right;
  }
</style>
